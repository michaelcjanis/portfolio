function project1
clc
clear all;

trans_x=load('x_transm.m'); %loads values from tables
trans_y=load('y_transm.m');
P=load('p_initial.m');
P_n=load('p_initial.m');
dx=load('dx.m');
dy=load('dyt.m');
dy=dy';
Block_Area=dx.*dy;
dz=load('dz.m');
Block_Volume=Block_Area.*dz;
Depth=load('depth.m');
x_perm=load('x_perm.m');
x_perm=x_perm./1000;
y_perm=load('y_perm.m');
y_perm=y_perm./1000;
Porosity=load('Porosity.m');
Delta_T=1;                          %time step
 % viscosity, will be a function of pressure = 6*10^-9(pressure)^2-5*10^-5(prssure)+1.0121
Mu=zeros(9,12);                           
for i=1:9
    for j=1:12  %initializing Mu for P values
        Mu(i,j)=6E-9*(P(i,j)^2)-5E-5*P(i,j)+1.0121;   
    end
end

% B formation volume factor = 1/(1+0.000009*(pressure-14.7))
FVF=zeros(9,12);             

for i=1:9  % initialize B for P values
    for j=1:12
        FVF(i,j)= 1/(1+0.000009*(P(i,j)-14.7));  
    end
end

Phi=zeros(9,12);   % Phi=porosity will be kept constant through out calculations


Rho=zeros(9,12);    % density of oil
for i=1:9         %initialize density of oil
    for j=1:12
       Rho(i,j)=52.4*(1+0.000009*(P(i,j)-14.7));
    end
end
 % Gamma for oil; would be matrix if Rho was updated for pressure change
Gamma_l=zeros(9,12);
for i=1:9
    for j=1:12
Gamma_l(i,j)=(0.21584E-3)*Rho(i,j)*32.17;     
    end
end

num=0;       %num and count are values used to build the matrices
count=0;   
  
   for k=1:60         %k=timestep index...DO NOT MIX UP WITH LOCATION INDEX
   num=num+1;   
   
  for iteration=1:3
    count=0; 
    CM=zeros(108,108);     % CM=calculated matrix = tri diagonal left hand side

     RHS=zeros(108,1);     % Right hand side of the matrix equation
    for i=1:9
        for j=1:12
            S=0;W=0;E=0;N=0;C=0;Q=0;Gamma=0;Sg=0;Wg=0;Eg=0;Ng=0;J=0;Cg=0;
            %transmissibility in the center of the current cellblock in the x direction
            Tx_cell=1.127*(dy(i,j)*dz(i,j)*x_perm(i,j))/(Mu(i,j)*FVF(i,j)*dx(i,j)); 
            %transmissibility in the center of the current cellblock in the y direction
            Ty_cell=1.127*(dx(i,j)*dz(i,j)*y_perm(i,j))/(Mu(i,j)*FVF(i,j)*dy(i,j));      
           
            if j==1      %western boundary of grid
                W=0;
                Wg=0; 
       
            elseif x_perm(i,j-1)==0     %check no western xperm within grid in previous blocks; redundant
                    W=0;
                    Wg=0;
            elseif x_perm(i,j)==0
                W=0;
                Wg=0;
            else           
                %harmonic average of transmissibility of previous x block and current
                temptrans=1.127*dy(i,j-1)*dz(i,j-1)*x_perm(i,j-1)/(Mu(i,j-1)*FVF(i,j-1)*dx(i,j-1));
                o=(1/Tx_cell)+(1/temptrans);   
               o=(1/2)*o;
               W=1/o;
                Wg=(W*Gamma_l(i,j))*Depth(i,j-1);
            end           %finished calculating western transmissibility
                       
           if j==12   %Start calculating eastern transmissibility 
                E=0;
                Eg=0;
            elseif x_perm(i,j+1)==0     %check no eastern xperm within grid in previous blocks
                    E=0;
                    Eg=0;
           elseif x_perm(i,j)==0 
               E=0;
               Eg=0;
           else
                %harmonic average of transmissibility of next x block and current
                temptrans=(1.127*(dy(i,j+1)*dz(i,j+1)*x_perm(i,j+1))/(Mu(i,j+1)*FVF(i,j+1)*dx(i,j+1)));
                o=(1/Tx_cell)+(1/temptrans);  
              o=(1/2)*o;
              E=1/o;
                Eg=(E*Gamma_l(i,j))*Depth(i,j+1);
                
            end           %finished calculating eastern transmissibility          
        
            if i==1      %northern boundary of grid
                N=0;
                Ng=0; 
       
            elseif y_perm(i-1,j)==0     %check no northern yperm within grid in previous blocks; redundant
                    N=0;          
                    Ng=0;
                   
            elseif x_perm(i,j)==0
                N=0;
                Ng=0;
            else
                %harmonic average of transmissibility of previous y block and current
                temptrans=1.127*(dx(i-1,j)*dz(i-1,j)*y_perm(i-1,j))/(Mu(i-1,j)*FVF(i-1,j)*dy(i-1,j));
                o=(1/Ty_cell)+(1/temptrans);   
                o=(1/2)*o;
                N=1/o;              
           
                Ng=(N*Gamma_l(i,j))*Depth(i-1,j);
             
            end           %finished calculating northern transmissibility         
          
           if i==9   %Start calculating southern transmissibility 
                S=0;
                Sg=0;
           elseif x_perm(i,j)==0
               S=0;
               Sg=0;
       
            elseif x_perm(i+1,j)==0     %check no southern yperm within grid in previous blocks
                    S=0;
                    Sg=0;
           
           else
               %harmonic average of transmissibility of next y block and current
                temptrans=1.127*(dx(i+1,j)*dz(i+1,j)*y_perm(i+1,j))/(Mu(i+1,j)*FVF(i+1,j)*dy(i+1,j));
                o=(1/Ty_cell)+(1/temptrans);   
                o=(1/2)*o;
                S=1/o;              
                Sg=(S*Gamma_l(i,j))*Depth(i+1,j);
              
            end           %finished calculating southern transmissibility 
           Cg=-(W+S+N+E)*Gamma_l(i,j)*Depth(i,j);         
           
            %determine if it is a block with a well to calculate C,Q, and
            %Gamma; B will not be solved for iterativly but will just be
            %updated each time
            
           if i==3 && j==9    % W-2 constant production rate
              
                A=(y_perm(i,j)/x_perm(i,j));
                B=(x_perm(i,j)/y_perm(i,j));
                %defines equivalent radius of the well in non square well block peaceman approx
                req=0.28*sqrt(sqrt(y_perm(i,j)/x_perm(i,j))*(dx(3,9)^2)+sqrt(x_perm(i,j)/y_perm(i,j))*(dy(3,9)^2))/(A^.25+B^.25); 
                kH=sqrt(x_perm(i,j)*y_perm(i,j)); %horizontal perm geometric mean
                %J in constant flow well
                Jc=(2*pi*1.127*kH*dz(i,j))/(Mu(i,j)*FVF(i,j)*(log(req/0.25)+0));         
                %pwf=(-650/Jc)+P(i,j);    %calculate sandface pressure             
                
                Gamma=(Block_Volume(i,j)*Porosity(i,j)*0.000009)/(5.614583*Delta_T); %gamma with no iteration for B
                 C=-(E+W+S+N+Gamma );         %C with constant production
                 Q=-(Gamma*P_n(i,j)-(Wg+Eg+Ng+Sg+Cg)-650);   %Q with constant production                     
              
            elseif i==4 && j==4 % W-3 constant pressure
                
                if P(i,j)<=5600 %forces J to 0 when block pressure  < pwf
                    J=0;
                else
                %defines equivalent radius of the well in non square well block peaceman approx
                A=(y_perm(i,j)/x_perm(i,j));
                B=(x_perm(i,j)/y_perm(i,j));
                req=0.28*sqrt(sqrt(y_perm(i,j)/x_perm(i,j))*(dx(4,4)^2)+sqrt(x_perm(i,j)/y_perm(i,j))*(dy(4,4)^2))/(A^.25+B^.25); 
                kH=sqrt(x_perm(i,j)*y_perm(i,j)); %horizontal perm geometric mean                     
                %determine J value on page 113...Sk skin factor = 0 assuming no damage in reservoir
                J=(2*pi*1.127*kH*dz(i,j))/(Mu(i,j)*FVF(i,j)*(log(req/0.25)+0)); 
                
                end               
    
                Gamma=(Block_Volume(i,j)*Porosity(i,j)*0.000009)/(5.614583*Delta_T); %gamma where B=1
                C=-(E+W+S+N+Gamma+J); % C for constant pressure well
                Q=-(Gamma*P_n(i,j)-(Wg+Eg+Ng+Sg+Cg)+J*5600); % Q with constant pressure well....J*sandface pressure of well
               
           else              
                
                 Gamma=(Block_Volume(i,j)*Porosity(i,j)*0.000009)/(5.614583*Delta_T);
                 C=-(E+W+S+N+Gamma);         %C with no production 
                 Q=-(Gamma*P_n(i,j)-(Wg+Eg+Ng+Sg+Cg));   %Q with no production 
                 
           end              
                
     
    %Start loading values into calculated matrix:
  
    count=count+1;  %gives me a value for the RHS matrix index; gives me my row index for CM matrix
   
    RHS(count,1)=Q;  %loads Q value into right hand side
                 
    
    CM(count,count)=C; %C value always on diagonal
    
    if S~=0
        CM(count,count+12)=S;  %load S into matrix if non zero
    end
   
    if W~=0
        CM(count,count-1)=W;  % load W into CM
    end
    
    if E~=0
        CM(count,count+1)=E;   % load E into CM
    end
    
    if N~=0
        CM(count,count-12)=N;  % load N into CM 
    end 
    
        end
    end
    
 CM( ~any(CM,2), : ) = []; %removes zeros from rows
CM( :, ~any(CM,1) ) = [];  %removes zeros from columns
RHS( ~any(RHS,2), : ) = []; %removes zeros from rows

 Ptemp=zeros(60,1); 
    
  Ptemp=CM\RHS;  %solve for new pressures
  
    
    val=0;
    for v=1:9    %save perssure values from vector in matrix form
        for u=1:12
            if x_perm(v,u)~=0
            val=val+1;   %to count index of Ptemp...column vector
            P(v,u)=Ptemp(val,1);
            else
                P(v,u)=0;
            end
        end
    end 
 
    
for v=1:9   % update B for new P values
    for u=1:12
        FVF(v,u)= 1/(1+0.000009*(P(v,u)-14.7));   
    end
end

for v=1:9   %update Mu for new Pessure values
    for u=1:12
        Mu(v,u)=6E-9*(P(v,u)^2)-5E-5*P(v,u)+1.0121;  
        
    end
end

for i=1:9  %density updated for new pressure value
    for j=1:12
        Rho(i,j)=52.4*(1+0.000009*(P(i,j)-14.7));
    end
end

for i=1:9   % Gamma for oil updated with new pressure
    for j=1:12
Gamma_l(i,j)=(0.21584E-3)*Rho(i,j)*32.17;     
    end
end

  end   % iteration loop ends
  
  
   for v=1:9    %The new time level pressure is saved
        for u=1:12      
                       
                P_n(v,u)=P(v,u);            
        end
   end  

  Jm(k,1)=P(4,4);  
end

pres_true=load('p60.m');
error=zeros(9,12);
for i=1:9
    for j=1:12
        error(i,j)=abs(pres_true(i,j)-P(i,j))/pres_true(i,j)*100;
    end
end

error
pres_true

