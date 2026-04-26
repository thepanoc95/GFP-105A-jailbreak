data = open('dump.bin','rb').read()
open('preloader.bin','wb').write(data[0x0000:0x8000])

