% silnik 148877 (150W, 48V)
nazwa_silnika='136211';
n_n=10400 ; %predkosc obrotowa [rad/s]
n_0=9730 ; %predkosc nominalna [rad/s]
I_0=0.834 ; %prad w uzwojeniu rotora bez obciazenia [A]
I_cont=10.2; % prad nominalny (maksymalny ciagly) [A]
I_start=175; % prad rozruchowy [A]
M_Rcont=0.312 ; % moment nominalny (maksymalny ciagly) [Nm]
M_RH=5.750;  % moment blokowania [Nm]
k_M=32.8 *10^(-3); % stala momentu [Nm/A]
J_R=209*10^(-3)*(10^(-2))^2; % moment bezwladnosci walu [kgm^2]
m_R=1.10; % masa silnika [kg]

%223090
%223093
%223095