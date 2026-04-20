import struct, sys
data = open('preloader.bin','rb').read()
for i in range(0, len(data)-3, 4):
  v = struct.unpack_from('<I', data, i)[0]
  if v in (0x800500000, 0x80030000, 0x80020000, 0x80000000):
    print(f'offset {i:#08x} = {v:#010x}')

