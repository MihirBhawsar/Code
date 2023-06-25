const mongoose = require("mongoose");
const mongoosePaginate = require("mongoose-paginate-v2");
//1.sechma
//2.model
//3.export
//use->model->queries

const jobSchema = new mongoose.Schema({
  postName: {
    type: String,
    require: [true, "you must enter the name of post"],
    default: "sde",
    enum: ["sde", "analyst", "ui", "hr", "manager"],
  },
  companyName: {
    type: String,
    require: true,
    default: "Name not given",
  },
  ctc: {
    type: Number,
    required: true,
  },
  location: String,
  cgpa: {
    type: Number,
    required: true,
    min: 0,
    max: [10, "Maximum allowed value for cgpa is 10"],
  },
  status:{
    type:String,
    enum:['active','over','interview'],
    default:'active'
  },
  description: String,
  numberOfPositions: Number,

});

jobSchema.plugin(mongoosePaginate);
const jobModel= mongoose.model('job',jobSchema);
module.export=jobModel;
// module.export= mongoose.model('job',jobSchema);

