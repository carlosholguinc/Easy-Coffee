// server.js

// set up ======================================================================
// get all the tools we need
var express  = require('express');
var app      = express();
var port     = process.env.PORT || 8080;
var mongoose = require('mongoose');
var passport = require('passport');
var flash    = require('connect-flash');
var server 	 = app.listen(port);

var io = require('socket.io').listen(server);


var serialport = require('serialport');
var Serialport = serialport.SerialPort;

io.on('connection', function(socket){
	console.log("Alguien se conectó");
});



var myPort = new serialport("COM11", {
	baudRate: 9600
});

myPort.on('open', onOpen);
myPort.on('data', onData);

function onOpen(){
	console.log("Se ha conectado un Arduino");
}

function onData(data){
	io.sockets.emit('lectura',data.toString('utf8'));
	//console.log('Data:', data.toString('utf8'));
}

var morgan       = require('morgan');
var cookieParser = require('cookie-parser');
var bodyParser   = require('body-parser');
var session      = require('express-session');

var configDB = require('./config/database.js');

// configuration ===============================================================
mongoose.connect(configDB.url); // connect to our database

require('./config/passport')(passport); // pass passport for configuration

// set up our express application
app.use(morgan('dev')); // log every request to the console
app.use(cookieParser()); // read cookies (needed for auth)
app.use(bodyParser.json()); // get information from html forms
app.use(bodyParser.urlencoded({ extended: true }));

app.set('view engine', 'ejs'); // set up ejs for templating

// required for passport
app.use(session({
    secret: 'ilovescotchscotchyscotchscotch', // session secret
    resave: true,
    saveUninitialized: true
}));
app.use(passport.initialize());
app.use(passport.session()); // persistent login sessions
app.use(flash()); // use connect-flash for flash messages stored in session


app.use(express.static('public'));

// routes ======================================================================
require('./app/routes.js')(app, passport, io); // load our routes and pass in our app and fully configured passport


// launch ======================================================================

console.log('The magic happens on port ' + port);
