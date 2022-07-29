clc
clear all;

Z_1=100;                % left most depth of the water table
Z_2=99;                % right most thickness of the water table
L=5000;                 % length of the water table
w=2;                   % width of one grid block in feet
Delta_T=1;             % time step

h=zeros(1,L/w);

for i=1:L/w
h(i)=500;                 % height of water table top above mean sea level in feet
end                      % can have a unique value for each grid block

Ax=((h(L/w)-Z_2)-(h(1)-Z_1))/L                %slope in meters/meters=dimensionless
Delta_Y=Ax*w;            %meters; change in height of Z-dimension of the blocks

%grid
h_block=ones(1,L/w);             % Height string of grid blocks with Z1 at the begining 
Delta_Y_1=Ax*(w/2);       %Sets up the initial change in height of the first grid block
h_block(1)=Z_1-Delta_Y_1;       % first height value 

for i=2:(L/w)
    h_block(i)=h(i)-(h(i-1)-h_block(i-1)+Delta_Y);    %sets up the rest of the heights for the grid blocks
end
Area=ones(1,L/w);               % Area string intializing
for i=1:(L/w)
    Area(i)=w*h_block(i);           % Loading values in the area string ft^2
end


RHS=zeros(L/w,1);

Kx=1.7;  %hydraulic conductivity  ft/day (pervious medium)

T=zeros(1,L/w);      %initialize transmissivity (will change for each block T=K*Z

for i=1:L/w
    T(1,i)=Kx*h_block(i); %calculate Transsmissivity for each grid block
end

Sy=0.27; % specific yield 'S' is ratio Sy=Vwd/Vt (V of water drained)/(total material volume)

 x=1:L/w;
 x=x.*2;
 plot(x,h_block); % generates plot of initial thicknesses
 title('Posistion on Aquifer vs. Water Table Thickness')
 xlabel('Distance from left boundary of aquifer (ft)')
 ylabel('Thickness of aquifer (ft)')

for i=1:200
    E=0;W=0;C=0;count=0;CM=zeros((L/w),(L/w));
    
    for j=1:L/w
        
        % used in case 2
      % if j>L/(2*w) 
       %    Kx=1.7;
      % elseif j==L/(4*w)
      %      Kx=.0000028;
     %  else
       %    Kx=1.7;
     %  end
        
        if j==1
            W=0;
        else
            W=(((Ax*Kx)/(Sy*2*w))+(T(1,j)/(Sy*w*w)));        
        end
        
        
        if j==L/w
            E=0;
        else
            E=((T(1,j)/(Sy*w*w))-((Ax*Kx)/(Sy*2*w)));            
        end
            
        C=-(1/Delta_T)-((2*T(1,j))/(Sy*w*w));   %coefficient of Zi
        
        % used in case 1
        %  I=0.0027;
        
        
       % used in case 3 
        if  j==500
            I=.167;
        elseif j==1250
            I=0.167;
        elseif j==2000
            I=.167;
        else
        I=0.00;
        end
     
        %used in case 2
     %  if j<L/(2*w) %&& j>L/(4*w)
      %   I=.0027;
      % else
      %     I=0;
      % end
       
           
        if j==1 %moves the W coefficient and Z_1 value to right side to preserve thickness at left edge
           RHS(j,1)=-(h_block(j)/Delta_T)-(I/Sy)-((((Ax*Kx)/(Sy*2*w))+(T(1,j)/(Sy*w*w))))*Z_1;       
        elseif j==L/w  %moves the W coefficient and Z_1 value to right side to preserve thickness at right edge            
            RHS(j,1)=-(h_block(j)/Delta_T)-(I/Sy)-(((T(1,j)/(Sy*w*w))-((Ax*Kx)/(Sy*2*w))))*Z_2; 
        else
            RHS(j,1)=-(h_block(j)/Delta_T)-(I/Sy);
        end     
        
        count=count+1;   
        CM(count,count)=C;        
        if E~=0
        CM(count,count+1)=E;
        end        
        if W~=0
        CM(count,count-1)=W;
        end
        
    end

     h_block=CM\RHS;
     
     for k=1:L/w
    T(1,k)=Kx*h_block(j); %update Transsmissivity for each grid block
     end
end
   
    hold all
    plot(x,h_block); %adds final thicknesses to plot of original thicknesses




    
