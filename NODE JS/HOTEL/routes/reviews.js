const express = require("express");
const router = express.Router();
const Hotel = require("../models/hotels");
const Review = require("../models/reviews");

//MIDDLEWARE
const { isLoggedIn, checkReviewUser } = require("../middlewares/index");
//controllers
const reviewController = require("../controllers/review");
// CUD
// new
router.get("/hotels/:id/reviews/new", reviewController.showReviewForm);
// create
router.post("/hotels/:id/reviews", isLoggedIn, reviewController.addReview);
// edit
router.get(
  "/hotels/:id/reviews/:reviewId/edit",
  isLoggedIn,
  checkReviewUser,
  reviewController.showEditReview
);
// update
router.patch(
  "/hotels/:id/reviews/:reviewId",
  isLoggedIn,
  checkReviewUser,
  reviewController.updateReview
);
// delete

router.delete(
  "/hotels/:id/reviews/:reviewsId",
  isLoggedIn,
  checkReviewUser,
  reviewController.deleteReview
);

module.exports = router;
