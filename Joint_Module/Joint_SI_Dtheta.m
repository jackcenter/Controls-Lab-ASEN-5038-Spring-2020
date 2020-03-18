clear; clc; close all;

load('Joint_SI_CL_40s_dtheta_Data.mat')
load('Joint_Init_Data.mat')
load('ID_parameters.mat')

R = fft(u);
dTheta_tf = fft(dTheta);

index1 = find(F<20 * T/(2*pi)); 
% G = 0*dTheta_tf;
% G(index1) = dTheta_tf(index1)./(R(index1)+dTheta_tf(index1));
% G(index1) = abs(G(index1));
G = dTheta_tf./(R + dTheta_tf);
G_log = 20*log10(G);
G_log = G_log(index1);
plot_index = find(G_log < -4);


% Making changes
G_log = G_log(plot_index);
F = F(plot_index);

K = mean(G_log(3:5));
K_3dB = K - 3;

figure
semilogx(F, G_log, 'k.')
hold on

s = tf('s');

Index_id2 = find(G_log(2:end) < K_3dB);
Index_id2 = Index_id2(1)+20;
omega1 = F(Index_id2);
omega1 = 28.3;
omega2 = 28.3;
omega3 = 180;

eta = 0.02;
H_at = db2mag(K)/Ks_J2*(s^2 + B2_J2*s + Ks_J2) / ((s/omega1 + 1)*(s/omega2 + 1) *(s/omega3 + 1));
H_at = .0008*(s^2 + eta*56.6*s + 800) / ((s/omega1 + 1)*(s/omega2 + 1) *(s/omega3 + 1));
bodemag(H_at)
hold off

% [mag, ~, wout] = bode(H, {.1,1000});
% NEED TO ID OFF OF THIS PLOT

function plot_data(x1, y1, x2, y2)

figure
hold on
plot(x1, mag2db(y1))
set(gca, 'XScale', 'log')
semilogx(x2, y2, '.')
legend("Transfer Function", "Experiment Data", "Location", "southwest")
xlim([.1,100])
xlabel("Frequency (rad/s)")
ylim([-80, 40])
ylabel("Magnitude (dB)")
hold off

end
