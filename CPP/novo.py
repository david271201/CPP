import pyautogui
import requests
response = requests.get("https://www.google.com")

# Extract the URL from the response
url = response.url