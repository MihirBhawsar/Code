const User = require("../models/users");
module.exports.authUser = async (
  req,
  accessToken,
  refreshToken,
  profile,
  done
) => {
  try {
    if (!req.user) {
      const user = await User.findOne({ googleId: profile.id });
      if (user) {
        //means user exits and login
        done(null, user);
      }
      //register
      const newUser = new User({
        googleId: profile.id,
        googleToken: accessToken,
        username: profile.email,
        name: profile.given_name + " " + profile.family_name,
      });
      await newUser.save();
      done(null, newUser);
    } else {
      //already logged in
      console.log("already logged in ");
      done(null, false, req.flash("error", "already logged in"));
    }
  } catch (error) {
    return done(error, null);
  }
};
