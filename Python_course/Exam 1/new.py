import pyautogui
n = int(input())
for i in range(n+1):
    pyautogui.write('#'*i)
    pyautogui.write('\n')
