from pytube import YouTube
from sys import argv

arg_iterator = 1
doDownload = False

if len(argv) > 1:
    # filter args here
    if argv[1] == '-d':
        doDownload = True
    
    # the link will always be the last arg
    link = argv[len(argv) - 1]
else:
    link = argv[1]

yt = YouTube(link)
if doDownload:
    yd = yt.streams.get_highest_resolution()
    yd.download(r'pydownload')

print("Title: ", yt.title)
print("Views: ", yt.views)
input(" ")