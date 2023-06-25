const mongoose=require('mongoose');
const passportLocalMongoose = require('passport-local-mongoose');

const userSchema=new mongoose.Schema({
username:{
    type:String,
    unique:true,
    require:true

},
dob:String,
phone:String,
gender:String,
isAdmin:{
    type:Boolean,
    default:false
},
cgpa:{
    type:Number,
    min:0,
    max:10
}
});

userSchema.plugin(passportLocalMongoose);
module.export=mongoose.model('user',userSchema);