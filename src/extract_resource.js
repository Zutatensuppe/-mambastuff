const fs = require('fs');
const path = require('path');

// === CONFIG ===
const inputFile = 'MAMBA.EXE';         // replace with your actual filename
const outputFile = 'resource_chunk.bin';
const offset = 0x14720;                // start offset
const length = 0x8A70;                 // number of bytes to extract

// === EXTRACTION ===
fs.open(inputFile, 'r', (err, fd) => {
  if (err) throw err;

  const buffer = Buffer.alloc(length);

  fs.read(fd, buffer, 0, length, offset, (err, bytesRead) => {
    if (err) throw err;

    fs.writeFile(outputFile, buffer, (err) => {
      if (err) throw err;
      console.log(`✅ Extracted ${bytesRead} bytes to ${outputFile}`);
    });

    fs.close(fd, (err) => {
      if (err) throw err;
    });
  });
});
