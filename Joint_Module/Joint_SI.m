clc; close all;
load('Pendelum_SI2.mat')
load('Motor_initialization_data.mat')

% FFT of input and ouput 
U = fft(u);
Y = fft(Theta);


index0 = find(abs(U/length(U)) >= 9e-2); 
B = 0*U;                     
B(index0) = Y(index0)./U(index0);        %System Response 
B(index0) = abs(B(index0));               %Magnitude of System Response
B_log = 20*log10(B);
        
figure()
semilogx(F,B_log,'r')
hold on

K = mean(B_log(2:4));
K_3dB = K - 3;
Index_tau = find(B_log(2:end) < K_3dB);
Index_tau = Index_tau(1)+1;
omega1 = F(Index_tau);
omega2 = 10.5;

%% First Order Transfer Function
s = tf('s');
H1 =  db2mag(K) / (s/omega1 + 1);
[mag ph wout] = bode(H1);
Mag = reshape(mag,[],size(mag,2),1);
Mag = mag2db(Mag);
% plot(wout, Mag)
% grid on 
H2 = db2mag(K) / ((s/omega2 + 1)*(s/omega1 + 1));
bodemag(H2)

a = 13.96;
b = 36.29;
c = 20.51;
% a = 18.14;
% b = 47.12;
% c = 24.88;

save("Pendelum_TF2.mat", "H2", "a", "b", "c", "omega1", "omega2")

% save("Pendelum_TF.mat", "H2", "a", "b", "c", "omega1", "omega2")
%% Control Law
% 
% % rltool(H2)
% 
% %C_TF = 9.9299 * (s+3.615)*(s+31.61)/(s*(s+49.63));
% % H_DT_second_order = tf([9.92 -19.19 9.266], [1 -1.906 0.9055], 0.002);
% % H_CT_second_order = d2c(H_DT_second_order)
% 
% % save("Pendulem_Controller2.mat", "C")
% load("Pendulem_Controller2.mat")
% C_D = c2d(C,0.002);
% 
% H_CL = C*H2/(1+C*H2);
% 
% load('integrator_controller.mat')
% figure()
% plot(Time, Theta, '-.r','Linewidth',1)
% hold on
% lsim(H_CL_I,r,Time)