const debug = require('debug')('app')
const SerialPort = require('serialport')
const Readline = require('@serialport/parser-readline')
const port = new SerialPort("/dev/tty.usbserial-14310", { baudRate: 9600 });

const parser = new Readline()
port.pipe(parser)

parser.on('data', line => debug(`> ${line}`))



// About SerialPort · Node SerialPort
// https://serialport.io/docs/guide-about