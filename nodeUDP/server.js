var PORT            = 5353;
var MULTICAST_GROUP = "224.0.0.251";

var dgram = require("dgram");

var client = dgram.createSocket("udp4");
var name = "IRKitD2A8";

var payload = new Buffer(
    [].concat( [ 0x00, 0x00, // ID
                 0x00, 0x00, // fixed
                 0x00, 0x01, // QDCount: number of entries in the Question Section
                 0x00, 0x00,
                 0x00, 0x00,
                 0x00, 0x00
               ],
               name.length,
               name.split("").map( function(letter) {
                   return letter.charCodeAt(0);
               }),
               "local".length,
               "local".split("").map( function(letter) {
                   return letter.charCodeAt(0);
               }),
               0x00, // NULL terminate
               [ 0x00, 0x01, // QTYPE
                 0x80, 0x01  // QCLASS
                 // http://tools.ietf.org/html/draft-cheshire-dnsext-multicastdns-06#section-6.5
                 // Multicast DNS defines the top bit in the class field of a DNS question as the "unicast response" bit.
               ]
             )
);
client.on("message", function(message, rinfo) {
    console.log("received: ",message,rinfo);
});
client.on("listening", function() {
    console.log("listening on ",client.address());

    client.setBroadcast(true);
    client.setTTL(64);
    client.setMulticastTTL(64);
    client.setMulticastLoopback(true);
    client.addMembership(MULTICAST_GROUP);
    client.send(payload, 0, payload.length, PORT, MULTICAST_GROUP, function(err,bytes) {
        console.log("err: "+err+" bytes: "+bytes);
        // client.close();
    });
});
client.on("close", function() {
    console.log("closed");
});
client.on("error", function(err) {
    console.log("error: ",err);
});
client.bind(5353);

