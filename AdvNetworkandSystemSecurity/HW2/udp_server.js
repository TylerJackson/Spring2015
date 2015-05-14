var PORT = 5020;
var HOST = '10.0.1.46';

//var dgram = require('dgram');
//var server = dgram.createSocket('udp4');
var dgram = require('dgram');
var server = dgram.createSocket('udp4');
server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});

server.on('message', function (message, remote) {
    console.log(remote.address + ':' + remote.port +' - ' + message);
    console.log(remote.info);
    console.log(remote.address.id);
    console.log(remote);
    console.log(message);
});

server.bind(PORT, HOST);