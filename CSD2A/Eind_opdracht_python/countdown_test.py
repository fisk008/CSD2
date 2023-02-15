
import pyautogui
print('Starting in ', end=''); pyautogui.countdown(3)

import pyautogui
fw = pyautogui.getActiveWindow(x,y)
fw.width # Gets the current width of the window.
1669
fw.topleft # Gets the current position of the window.
(174, 153)
fw.width = 1000 # Resizes the width.
fw.topleft = (800, 400) # Moves the window.