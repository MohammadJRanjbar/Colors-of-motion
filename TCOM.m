clear all 
clc 
close all
%Write the your directory here
folder =' C:\Users\Mohammad\Desktop\workspace\color';
%Writ the name of the video here  
V = VideoReader('vid.mp4');
Du=V.Duration;
FR=V.FrameRate;
AllFrames=Du*FR;
roundedframe=round (AllFrames);
L=roundedframe/1.5;
for K=1:roundedframe
    
I = double(read(V,K));
[m,n]=size(I);
R=0;
G=0;
B=0;
redChannel = I(:, :, 1);
greenChannel = I(:, :, 2);
blueChannel = I(:, :, 3);
R = sum(sum(redChannel));
G=  sum(sum(greenChannel));
B=  sum(sum(blueChannel));
R=R/(m*n);
B=B/(m*n);
G=G/(m*n); 
redChannel(:,:)=R;
greenChannel(:,:)=G;
blueChannel(:,:)=B;
OutImage(K,1:L,1)=redChannel(1,1);
OutImage(K,1:L,2)=greenChannel(1,1);
OutImage(K,1:L,3)=blueChannel(1,1);
end; 
B=uint8(OutImage);
imwrite(B,fullfile(folder,'Your_Name.jpg'));


