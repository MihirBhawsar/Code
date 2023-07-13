module.exports.showReviewForm = (req, res) => {
  res.render("reviews/new", { hotelId: req.params.id, page: "New Review" });
};
module.exports.addReview = async (req, res) => {
  try {
    const newReview = new Review(req.body.review);
    newReview.user = req.user._id;
    await newReview.save();
    const hotel = await Hotel.findById(req.params.id);
    hotel.reviews.push(newReview);
    hotel.totalRating++;
    hotel.sumOfRating += parseInt(req.body.review.stars, 10);
    hotel.averageRating = hotel.sumOfRating / hotel.totalRating;
    await hotel.save();
    req.flash("success", "posted a review");
    res.redirect(`/hotels/${req.params.id}`);
  } catch (error) {
    res.send(error);
    req.flash("error", "cannot post review at the moment");
    res.redirect(`/hotels/${req.params.id}`);
  }
};
module.exports.showEditReview = async (req, res) => {
  try {
    const review = await Review.findById(req.params.reviewId);
    res.render(`reviews/edit`, {
      hotelId: req.params.id,
      review,
      page: "Edit Review",
    });
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};
module.exports.updateReview = async (req, res) => {
  try {
    const hotel = await Hotel.findById(req.params.id);
    const review = await Review.findById(req.params.reviewId);
    await Review.findByIdAndUpdate(req.params.reviewId, req.body.review);
    hotel.sumOfRating -= parseInt(review.stars, 10);
    hotel.sumOfRating += parseInt(req.body.review.stars);
    hotel.averageRating = hotel.sumOfRating / hotel.totalRating;
    await hotel.save();
    req.flash("success", "hotel update successfully");
    res.redirect(`/hotels/${req.params.id}`);
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};
module.exports.deleteReview = async (req, res) => {
  try {
    const review = await Review.findById(req.params.reviewsId);
    const hotel = await Hotel.findById(req.params.id);
    await Review.findByIdAndDelete(req.params.reviewsId);
    hotel.sumOfRating -= parseInt(review.stars, 10);
    hotel.totalRating--;
    hotel.averageRating = hotel.sumOfRating / hotel.totalRating;
    await hotel.save();
    req.flash("success", "hotel delete successfully");
    res.redirect(`/hotels/${req.params.id}`);
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};
