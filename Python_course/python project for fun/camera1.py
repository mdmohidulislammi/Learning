import cv2

video_cap=cv2.VideoCapture(0)

while True:
    ret, video=video_cap.read()