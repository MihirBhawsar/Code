const mongoose = require("mongoose");
const passportLocalMongoose = require("passport-local-mongoose");
const userSchema = new mongoose.Schema({
  userName: String,
  name: String,
  age: Number,
  phone: String,
  address: String,
  googleId: String,
  googleToken: String,
});

userSchema.plugin(passportLocalMongoose);
module.exports = mongoose.model("user", userSchema);
