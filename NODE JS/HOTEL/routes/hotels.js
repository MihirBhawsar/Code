const express = require("express");
const router = express.Router();

const Hotel = require("../models/hotels");
//MIDDLEWARE
const { isLoggedIn, checkHotelAuthor } = require("../middlewares/index");
//CLOUDINARY
const multer = require("multer");
const storage = require("../cloudinary/index");
const upload = multer({ storage });

//MAPBOX
const geocoding = require("@mapbox/mapbox-sdk/services/geocoding");
const geoCodingClient = geocoding({ accessToken: process.env.MAPBOX_TOKEN });

//CONTACT FORM
const { sendEmail } = require("../middlewares/email");
const stripe = require("stripe")(process.env.STRIPE_SECRET_KEY);
//Controller
const hotelController = require("../controllers/hotel");

router.get("/", hotelController.showLandingPage);

router.get("/contact", hotelController.contactPage);

router.post("/contact", hotelController.sendMail);

router.get("/hotels", hotelController.allHotelList);

router.get("/hotels/new", isLoggedIn, hotelController.NewHotelPage);

router.post(
  "/hotels",
  isLoggedIn,
  upload.array("image"),
  hotelController.addNewHotel
);

router.get("/hotels/:id", isLoggedIn, hotelController.ShowHotel);

router.get("/hotels/:id/edit", hotelController.editPage);

router.patch(
  "/hotels/:id",
  isLoggedIn,
  checkHotelAuthor,
  hotelController.hotelUpdate
);

router.delete(
  "/hotels/:id",
  isLoggedIn,
  checkHotelAuthor,
  hotelController.deleteHotel
);

router.get("/hotels/:id/checkout", isLoggedIn, hotelController.bookHotel);

router.get("/success", hotelController.paymentSuccess);

router.get("/cancel", hotelController.paymentError);

router.get("/hotels/:id/upvote", isLoggedIn, hotelController.onLike);

router.get("/hotels/:id/downvote", isLoggedIn, hotelController.onDislike);

module.exports = router;
