const mongoose = require('mongoose');
const notifSchema=new mongoose.Schema({
    title:{
        required:true,
        type:String
    },
    body:String ,
    author:String
});

module.exports=mongoose.model('notification',notifSchema);