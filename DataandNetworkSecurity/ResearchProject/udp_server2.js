var PORT = 2080;
var HOST = '192.168.1.8';

//var dgram = require('dgram');
//var server = dgram.createSocket('udp4');
var raw = require ("raw-socket");
var server = raw.createSocket({protocol: raw.Protocol.UDP});

server.on("message",function(buffer,source){
	console.log("received " + buffer.length + " bytes from " + source + ": " + buffer.toString("hex"));
	var buffString = buffer.toString("hex");
	console.log("data : " + buffString.slice(56,buffString.length));
	console.log("ip id: " + buffString.slice(8,12));
});
