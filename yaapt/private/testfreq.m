close all
load('target_freq.mat')
load('bin_freq.mat')
load('bin_cnt.mat')
target_freq = FreqData(:,2);


% Fs = 44100;
% recObj = audiorecorder(Fs, 16, 1);
% disp('Start speaking.')
% recordblocking(recObj, 2);
% disp('End of Recording.');
% Data = getaudiodata(recObj);
% audiowrite('sample/record.wav',Data,Fs)
[Data, Fs] = audioread ('sample/record.wav');

bp_low = 20;
bp_high = 4410;
Filter_order = 150;
w1  = (bp_low / (Fs/2));
w2  = (bp_high / (Fs/2));
w   = [w1 w2];
bandpass = Myfir1(Filter_order,w);
Data = filter(bandpass,1,Data);

max_Fs = 8820;
if(Fs>max_Fs)
    dec_fac = Fs/max_Fs;
    dec_Fs = Fs/dec_fac;
    rate = rats(dec_fac);
    indx_slash = find(rate=='/', 1);
    if(~isempty(indx_slash))
      Q = str2double(rate(1:indx_slash-1));
      P = str2double(rate(indx_slash+1:end));
      dec_data = resample(Data,P,Q);
    else
        dec_data = decimate(Data,dec_fac);
    end
else
    dec_data = Data;
    dec_Fs = Fs;
end
player = audioplayer(dec_data,dec_Fs);
play(player);

fft_length = 8192*2;
window_length = 1;
n_window_length = window_length*dec_Fs;
n_overlap = floor(n_window_length/2);


if(fft_length>length(dec_data))
    zeropadded_dec_data = [dec_data;zeros(fft_length-length(dec_data),1)];
    tic
    s = fft(zeropadded_dec_data,fft_length);
    s = s(1:fix(length(s)/2)+1);
    f = linspace(0,dec_Fs/2,fft_length/2+1)';
    t = length(dec_data)/fft_length/2;
    toc
%     res_window = kaiser(fft_length);
%     tic
%     [s2,f2,t2] = spectrogram(zeropadded_dec_data,res_window,[],fft_length,dec_Fs,'yaxis');
%     toc
else
    res_window = kaiser(n_window_length);
    tic
    [s,f,t] = spectrogram(dec_data,res_window,n_overlap,fft_length,dec_Fs,'yaxis');
    toc
end








mag = abs(s);
% mag2 = abs(s2);
him = imagesc(t,f,mag);
axis xy
colormap(1-gray)
figure
plot(f,mag(:,1))
% figure
% plot(f2,mag2(:,1))
% target_mag=interp1(f,mag,target_freq,'nearest');
% plot(target_freq,target_mag(:,1))
c = fq2cnt(f);
numframes = size(mag,2);
pitch = zeros(2,numframes);

for i=1:numframes
    mag_window = mag(:,i);
    pitch_peaks = [
        max(mag_window(c>=bin_cnt_low(1,1)&c<=bin_cnt_high(1,1))) max(mag_window(c>=bin_cnt_low(1,2)&c<=bin_cnt_high(1,2)))...
        max(mag_window(c>=bin_cnt_low(1,3)&c<=bin_cnt_high(1,3))) max(mag_window(c>=bin_cnt_low(1,4)&c<=bin_cnt_high(1,4)))...
        max(mag_window(c>=bin_cnt_low(1,5)&c<=bin_cnt_high(1,5))) max(mag_window(c>=bin_cnt_low(1,6)&c<=bin_cnt_high(1,6)))...
        max(mag_window(c>=bin_cnt_low(1,7)&c<=bin_cnt_high(1,7))) max(mag_window(c>=bin_cnt_low(1,8)&c<=bin_cnt_high(1,8)))...
        max(mag_window(c>=bin_cnt_low(1,9)&c<=bin_cnt_high(1,9))) max(mag_window(c>=bin_cnt_low(1,10)&c<=bin_cnt_high(1,10)))...
        max(mag_window(c>=bin_cnt_low(1,11)&c<=bin_cnt_high(1,11))) max(mag_window(c>=bin_cnt_low(1,12)&c<=bin_cnt_high(1,12)));...
        
        max(mag_window(c>=bin_cnt_low(2,1)&c<=bin_cnt_high(2,1))) max(mag_window(c>=bin_cnt_low(2,2)&c<=bin_cnt_high(2,2)))...
        max(mag_window(c>=bin_cnt_low(2,3)&c<=bin_cnt_high(2,3))) max(mag_window(c>=bin_cnt_low(2,4)&c<=bin_cnt_high(2,4)))...
        max(mag_window(c>=bin_cnt_low(2,5)&c<=bin_cnt_high(2,5))) max(mag_window(c>=bin_cnt_low(2,6)&c<=bin_cnt_high(2,6)))...
        max(mag_window(c>=bin_cnt_low(2,7)&c<=bin_cnt_high(2,7))) max(mag_window(c>=bin_cnt_low(2,8)&c<=bin_cnt_high(2,8)))...
        max(mag_window(c>=bin_cnt_low(2,9)&c<=bin_cnt_high(2,9))) max(mag_window(c>=bin_cnt_low(2,10)&c<=bin_cnt_high(2,10)))...
        max(mag_window(c>=bin_cnt_low(2,11)&c<=bin_cnt_high(2,11))) max(mag_window(c>=bin_cnt_low(2,12)&c<=bin_cnt_high(2,12)));...
        
        max(mag_window(c>=bin_cnt_low(3,1)&c<=bin_cnt_high(3,1))) max(mag_window(c>=bin_cnt_low(3,2)&c<=bin_cnt_high(3,2)))...
        max(mag_window(c>=bin_cnt_low(3,3)&c<=bin_cnt_high(3,3))) max(mag_window(c>=bin_cnt_low(3,4)&c<=bin_cnt_high(3,4)))...
        max(mag_window(c>=bin_cnt_low(3,5)&c<=bin_cnt_high(3,5))) max(mag_window(c>=bin_cnt_low(3,6)&c<=bin_cnt_high(3,6)))...
        max(mag_window(c>=bin_cnt_low(3,7)&c<=bin_cnt_high(3,7))) max(mag_window(c>=bin_cnt_low(3,8)&c<=bin_cnt_high(3,8)))...
        max(mag_window(c>=bin_cnt_low(3,9)&c<=bin_cnt_high(3,9))) max(mag_window(c>=bin_cnt_low(3,10)&c<=bin_cnt_high(3,10)))...
        max(mag_window(c>=bin_cnt_low(3,11)&c<=bin_cnt_high(3,11))) max(mag_window(c>=bin_cnt_low(3,12)&c<=bin_cnt_high(3,12)));...
        
        max(mag_window(c>=bin_cnt_low(4,1)&c<=bin_cnt_high(4,1))) max(mag_window(c>=bin_cnt_low(4,2)&c<=bin_cnt_high(4,2)))...
        max(mag_window(c>=bin_cnt_low(4,3)&c<=bin_cnt_high(4,3))) max(mag_window(c>=bin_cnt_low(4,4)&c<=bin_cnt_high(4,4)))...
        max(mag_window(c>=bin_cnt_low(4,5)&c<=bin_cnt_high(4,5))) max(mag_window(c>=bin_cnt_low(4,6)&c<=bin_cnt_high(4,6)))...
        max(mag_window(c>=bin_cnt_low(4,7)&c<=bin_cnt_high(4,7))) max(mag_window(c>=bin_cnt_low(4,8)&c<=bin_cnt_high(4,8)))...
        max(mag_window(c>=bin_cnt_low(4,9)&c<=bin_cnt_high(4,9))) max(mag_window(c>=bin_cnt_low(4,10)&c<=bin_cnt_high(4,10)))...
        max(mag_window(c>=bin_cnt_low(4,11)&c<=bin_cnt_high(4,11))) max(mag_window(c>=bin_cnt_low(4,12)&c<=bin_cnt_high(4,12)));...
        
        max(mag_window(c>=bin_cnt_low(5,1)&c<=bin_cnt_high(5,1))) max(mag_window(c>=bin_cnt_low(5,2)&c<=bin_cnt_high(5,2)))...
        max(mag_window(c>=bin_cnt_low(5,3)&c<=bin_cnt_high(5,3))) max(mag_window(c>=bin_cnt_low(5,4)&c<=bin_cnt_high(5,4)))...
        max(mag_window(c>=bin_cnt_low(5,5)&c<=bin_cnt_high(5,5))) max(mag_window(c>=bin_cnt_low(5,6)&c<=bin_cnt_high(5,6)))...
        max(mag_window(c>=bin_cnt_low(5,7)&c<=bin_cnt_high(5,7))) max(mag_window(c>=bin_cnt_low(5,8)&c<=bin_cnt_high(5,8)))...
        max(mag_window(c>=bin_cnt_low(5,9)&c<=bin_cnt_high(5,9))) max(mag_window(c>=bin_cnt_low(5,10)&c<=bin_cnt_high(5,10)))...
        max(mag_window(c>=bin_cnt_low(5,11)&c<=bin_cnt_high(5,11))) max(mag_window(c>=bin_cnt_low(5,12)&c<=bin_cnt_high(5,12)));...

        max(mag_window(c>=bin_cnt_low(6,1)&c<=bin_cnt_high(6,1))) max(mag_window(c>=bin_cnt_low(6,2)&c<=bin_cnt_high(6,2)))...
        max(mag_window(c>=bin_cnt_low(6,3)&c<=bin_cnt_high(6,3))) max(mag_window(c>=bin_cnt_low(6,4)&c<=bin_cnt_high(6,4)))...
        max(mag_window(c>=bin_cnt_low(6,5)&c<=bin_cnt_high(6,5))) max(mag_window(c>=bin_cnt_low(6,6)&c<=bin_cnt_high(6,6)))...
        max(mag_window(c>=bin_cnt_low(6,7)&c<=bin_cnt_high(6,7))) max(mag_window(c>=bin_cnt_low(6,8)&c<=bin_cnt_high(6,8)))...
        max(mag_window(c>=bin_cnt_low(6,9)&c<=bin_cnt_high(6,9))) max(mag_window(c>=bin_cnt_low(6,10)&c<=bin_cnt_high(6,10)))...
        max(mag_window(c>=bin_cnt_low(6,11)&c<=bin_cnt_high(6,11))) max(mag_window(c>=bin_cnt_low(6,12)&c<=bin_cnt_high(6,12)));...
        
        max(mag_window(c>=bin_cnt_low(7,1)&c<=bin_cnt_high(7,1))) max(mag_window(c>=bin_cnt_low(5,2)&c<=bin_cnt_high(7,2)))...
        max(mag_window(c>=bin_cnt_low(7,3)&c<=bin_cnt_high(7,3))) max(mag_window(c>=bin_cnt_low(5,4)&c<=bin_cnt_high(7,4)))...
        max(mag_window(c>=bin_cnt_low(7,5)&c<=bin_cnt_high(7,5))) max(mag_window(c>=bin_cnt_low(5,6)&c<=bin_cnt_high(7,6)))...
        max(mag_window(c>=bin_cnt_low(7,7)&c<=bin_cnt_high(7,7))) max(mag_window(c>=bin_cnt_low(5,8)&c<=bin_cnt_high(7,8)))...
        max(mag_window(c>=bin_cnt_low(7,9)&c<=bin_cnt_high(7,9))) max(mag_window(c>=bin_cnt_low(5,10)&c<=bin_cnt_high(7,10)))...
        max(mag_window(c>=bin_cnt_low(7,11)&c<=bin_cnt_high(7,11))) max(mag_window(c>=bin_cnt_low(5,12)&c<=bin_cnt_high(7,12)));...
        ];
    sumofharm = sum(pitch_peaks);
    [~,pitch(1,i)] = max(sumofharm);
    [~,pitch(2,i)] = max(pitch_peaks(:,pitch(1,i)));
end



