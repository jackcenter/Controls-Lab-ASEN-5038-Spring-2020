clc; clear; close all;

load('Joint_Init_Data.mat')
load('ID_parameters.mat')
load('Joint_SI_Data.mat')

R = fft(u);
Y = fft(Theta);
F = 0:2*pi/T:pi/dT-2*pi/T; 
index0 = find(F<200 * T/(2*pi)); 
% index0 = find(abs(R/length(R)) >= 9e-2); 
B = 0*R;                     
B(index0) = Y(index0)./(R(index0)+ Y(index0));         %System Response 
B(index0) = abs(B(index0));               %Magnitude of System Response
B_log = 20*log10(B);

figure
semilogx(F(1:201), B_log(1:201), 'k.')
legend("Experiment Data", "Location", "southwest")
xlim([1,100])
xlabel("Frequency (rad/s)")
ylim([-80, 40])
ylabel("Magnitude (dB)")


%% Closed Loop TF Theta / V
load('Joint_Init_Data.mat')
load('Joint_SI_CL_40s_Data.mat')
% FFT of input and ouput 
R = fft(u);
Y = fft(Theta);

index0 = find(F<200 * T/(2*pi)); 
% index0 = find(abs(R/length(R)) >= 9e-2); 
B = 0*R;                     
B(index0) = Y(index0)./(R(index0)+ Y(index0));         %System Response 
B(index0) = abs(B(index0));               %Magnitude of System Response
B_log = 20*log10(B);

figure
semilogx(F, B_log, 'k.')
legend("Experiment Data", "Location", "southwest")
xlim([1,100])
xlabel("Frequency (rad/s)")
ylim([-80, 40])
ylabel("Magnitude (dB)")
        

%% Alpha / Theta
Theta_tf = Y;
Alpha_tf = fft(Alpha);

index1 = find(F<200 * T/(2*pi)); 
D = 0*Alpha_tf;
D(index1) = Alpha_tf(index1)./Theta_tf(index1);
D(index1) = abs(D(index1));
D_log = 20*log10(D);

% figure
% semilogx(F, D_log, 'k')
% hold on
s = tf('s');
w_n = 13.45;
xi = .05;
H_at = s^2/(s^2 + 2*xi*w_n*s + w_n^2);
% bodemag(H_at)
% hold off

[mag, ~, wout] = bode(H_at);
mag = reshape(mag, 1, []);
wout = reshape(wout, 1, []);


B2_J2 = 2*xi*w_n;
Ks_J2 = w_n^2;

save('ID_parameters.mat','B2_J2','Ks_J2', 'K_J1', 'B1_J1')

plot_data(wout, mag, F(1:197), D_log(1:197))
%% dTheta / R
load('Joint_SI_CL_40s_dtheta_Data.mat')

R = fft(u);
dTheta_tf = fft(dTheta);
G = 0*dTheta_tf;
G(index1) = dTheta_tf(index1)./R(index1);
G(index1) = abs(G(index1));
G_log = 20*log10(G);

K = mean(G_log(3:15));
K_3dB = K - 3;

figure
semilogx(F, G_log, 'k')
hold on
s = tf('s');

Index_id2 = find(G_log(2:end) < K_3dB);
Index_id2 = Index_id2(1)+20;
omega1 = F(Index_id2);
omega2 = 13;
omega3 = 15;

H_at = db2mag(K)/Ks_J2*(s^2 + B2_J2*s + Ks_J2) / ((s/omega1 + 1)*(s/omega2 + 1) *(s/omega3 + 1));
bodemag(H_at)
hold off

%% Theta / R
% K = mean(B_log(2:4));
% K_3dB = K - 3;

% Index_id1 = find(B_log(2:end) < K_3dB);
% Index_id1 = Index_id1(1)+20;
% omega1 = F(Index_id1);
% 
% figure()
% semilogx(F,B_log,'r')
% hold on
% 
% omega2 = 13;
% omega3 = 15;
% omega4 = 16;
% 
% H1 =  db2mag(K)/Ks_J2*(s^2 + B2_J2*s + Ks_J2) / ((s/omega1 + 1)*(s/omega2+1)*(s/omega3+1)*(s/omega4+1));
% bodemag(H1)
% 
% % Transfer Function Theta/Alpha
% Theta_other = Y;
% Alpha = fft(Alpha);
% 
% index1 = find(abs(Alpha/length(Alpha)) >= 9e-2); 
% index1 = 1:length(Alpha);
% B = 0*Alpha;
% B(index1) = Theta(index1)./(Alpha(index1) + Theta(index1));
% B(index1) = abs(B(index1));
% B_log = 20*log10(B);

% figure
% semilogx(F, B_log, 'k')

%% First Order Transfer Function
% s = tf('s');
% H1 =  db2mag(K) / (s/omega1 + 1);
% [mag ph wout] = bode(H1);
% Mag = reshape(mag,[],size(mag,2),1);
% Mag = mag2db(Mag);
% plot(wout, Mag)
% grid on 
% H2 = db2mag(K) / ((s/omega2 + 1)*(s/omega1 + 1));
% bodemag(H2)

function plot_data(x1, y1, x2, y2)

figure
hold on
plot(x1, mag2db(y1))
set(gca, 'XScale', 'log')
semilogx(x2, y2, '.')
legend("Transfer Function", "Experiment Data", "Location", "southwest")
xlim([1,100])
xlabel("Frequency (rad/s)")
ylim([-80, 40])
ylabel("Magnitude (dB)")
hold off

end
