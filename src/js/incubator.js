Pebble.addEventListener("ready", function(e) {
  console.log("Incubator, ready to go!");  

  var data = {
  	'rank' 			: 1234,
  	'playersCount' 	: 30000
  };
  MessageQueue.sendAppMessage(data);
});

Pebble.addEventListener("appmessage", function(e) {
  console.log("Incubator onAppMessage " + JSON.stringify(e.payload));
  console.log("egg_id " + payload.egg_id);
});
