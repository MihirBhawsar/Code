const express = require("express");
const router = express.Router();

const passport = require("passport");
const User=require('../models/users');
const {loginForm,loginUser,registerForm,registerUser ,logoutUser}=require('../controllers/auth');
router.get("/login", loginForm);

router.post(
  "/login",
  passport.authenticate("local", {
    failureFlash: true,
    failureRedirect: "/login",
  }),
  loginUser
);

router.get('/register',registerForm);

router.post("/register",registerUser );

router.get('/logout',logoutUser)

module.exports=router;