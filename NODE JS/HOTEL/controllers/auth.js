const User = require("../models/users");

module.exports.loginForm = (req, res) => {
  res.render("user/login", { page: "Login" });
};
module.exports.loginUser = (req, res) => {
  res.redirect("/hotels");
};
module.exports.registerForm = (req, res) => {
	res.render('users/register', { page: 'Register' });
};
module.exports.registerUser  = async (req, res) => {
  try {
    const userData = new User(req.body.user);
    const registeredUser = await User.register(userData, req.body.password);
    req.login(registeredUser, (error) => {
      if (error) {
        return res.send(error);
      }
      res.flash('success','registration successfully ');
      res.redirect("/hotels");
    });
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
     }
};
module.exports.logoutUser=(req,res)=>{
    req.logout((error)=>{
        if(error) {
          req.flash("error", "Something went wrong");
          return res.send(error)};
        res.flash('success','logout user');
        res.redirect('/hotels');
    })
}