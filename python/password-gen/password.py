import random
import string
import pyperclip

lenght = int(input("Enter a number:"))
random = ''.join([random.choice(string.ascii_letters + string.digits + string.punctuation ) for n in range(lenght)])
print(random)
clipboard_input = input("Copy to clipboard? y/n")
if clipboard_input == "y":
    pyperclip.copy(random)