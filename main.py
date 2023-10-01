try:
  import usocket as socket
except:
  import socket

def web_page():
    with open('./site/index.html') as fh:
        data = fh.read()
    return data


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 80))
s.listen(5)

while True:
  conn, addr = s.accept()
  print('Got a connection from %s' % str(addr))
  request = conn.recv(1024)
  #print('Content = %s' % str(request))
  response = web_page()
  conn.send(response)
  conn.close()
