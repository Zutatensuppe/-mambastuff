const http = require('http');
const fs = require('fs');
const path = require('path');
const formidable = require('formidable');

// Simple HTML form for upload
const formHTML = `
  <!doctype html>
  <html>
    <head><title>Upload file</title></head>
    <body>
      <h1>Upload a file</h1>
      <form action="/" method="post" enctype="multipart/form-data">
        <input type="file" name="file" />
        <input type="submit" value="Upload" />
      </form>
    </body>
  </html>
`;

const server = http.createServer((req, res) => {
  if (req.method.toLowerCase() === 'get') {
    // Serve the upload form
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end(formHTML);
  } else if (req.method.toLowerCase() === 'post') {
    // Handle file upload
    const form = new formidable.IncomingForm();
    form.parse(req, (err, fields, files) => {
        if (err) {
            res.writeHead(500);
            res.end('Error parsing the file');
            return;
        }

        console.log('Files received:', files);

        const oldPath = files.file[0].filepath;           // note: 'filepath' instead of 'path'
        const fileName = files.file[0].originalFilename;  // note: 'originalFilename' instead of 'name'

        if (!oldPath || !fileName) {
            res.writeHead(400);
            res.end('File path or name is missing');
            return;
        }

        const newPath = path.join(__dirname, fileName);

        fs.rename(oldPath, newPath, (err) => {
            if (err) {
            res.writeHead(500);
            res.end('Error saving the file');
            return;
            }
            res.writeHead(200, {'Content-Type': 'text/html'});
            res.end(`<p>File <strong>${fileName}</strong> uploaded successfully!</p><a href="/">Upload another</a>`);
        });
        });

  } else {
    res.writeHead(405);
    res.end('Method not allowed');
  }
});

const PORT = 5000;
server.listen(PORT, () => {
  console.log(`Server listening on http://localhost:${PORT}`);
});
