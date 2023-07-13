module.exports.allHotelList = async (req, res) => {
  try {
    const hotels = await Hotel.find();
    res.render("hotels/index", { hotels, page: "All Hotels-StaySense" });
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};
module.exports.NewHotelPage = (req, res) => {
  res.render("hotels/new", { page: "New Hotel-StaySense" });
};
module.exports.addNewHotel = async (req, res) => {
  try {
    const newHotel = new Hotel(req.body.hotel);
    newHotel.author = req.user._id;
    for (let img of req.files) {
      newHotel.image.push(img.path);
    }
    const query = req.body.hotel.address;
    const result = await geoCodingClient
      .forwardGeocode({
        query,
        limit: 1,
      })
      .send();
    newHotel.location = result.body.features[0].geometry;
    console.log(newHotel);

    await newHotel.save();
    res.redirect(`/hotels/${newHotel._id}`);
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};
module.exports.ShowHotel = async (req, res) => {
  try {
    // const hotel = await Hotel.findById(req.params.id);
    // res.render("hotels/show", { hotel, page: "Hotel Details-StaySense" });
    const { id } = req.params;
    let likeExists = null,
      dislikeExists = null;
    if (req.user) {
      likeExists = await Hotel.findOne({
        _id: id,
        upvotes: req.user._id,
      });
      dislikeExists = await Hotel.findOne({
        _id: id,
        downvotes: req.user._id,
      });
    }
    const hotel = await Hotel.findById(id).populate("reviews");
    const reviews = hotel.reviews;
    res.render("hotels/show", {
      likeExists,
      dislikeExists,
      reviews,
      hotel,
      page: "Hotel Details-StaySense",
    });
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};
module.exports.editPage = async (req, res) => {
  try {
    const hotel = await Hotel.findById(req.params.id);
    res.render("hotels/edit", { hotel, page: "Edit Hotel-StaySense" });
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};

module.exports.hotelUpdate = async (req, res) => {
  try {
    const hotel = await Hotel.findByIdAndUpdate(req.params.id, req.body.hotel);
    const query = req.body.hotel.address;
    const result = await geoCodingClient
      .forwardGeocode({
        query,
        limit: 1,
      })
      .send();
    hotel.location = result.body.features[0].geometry;
    await hotel.save();
    res.redirect(`/hotels/${req.params.id}`);
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};

module.exports.deleteHotel = async (req, res) => {
  try {
    await Hotel.findByIdAndRemove(req.params.id);
    res.redirect("/hotels");
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};
module.exports.bookHotel = async (req, res) => {
  try {
    const hotel = await Hotel.findById(req.params.id);
    const session = await stripe.checkout.sessions.create({
      payment_method_types: ["card"],
      line_items: [
        {
          price_data: {
            currency: "inr",
            product_data: {
              name: hotel.name,
              description: hotel.address,
              images: [hotel.image[0]],
            },
            unit_amount: hotel.price * 100,
          },
          quantity: 1,
        },
      ],
      mode: "payment",
      success_url: "http://localhost:3000/success",
      cancel_url: "http://localhost:3000/cancel",
    });
    res.redirect(session.url);
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};

module.exports.paymentSuccess = (req, res) => {
  res.send("payment successful");
};
module.exports.paymentError = (req, res) => {
  res.send("payment cancelled");
};
module.exports.onLike = async (req, res) => {
  try {
    const { id } = req.params;
    const likeExists = await Hotel.findOne({
      _id: id,
      upvotes: req.user._id,
    });

    const disLikeExists = await Hotel.findOne({
      _id: id,
      downvotes: req.user._id,
    });
    // check if user has already liked -> remove that like
    // check if user has already disliked -> change from dislike to like
    // else -> add a new like
    if (likeExists) {
      await Hotel.findByIdAndUpdate(id, {
        $pull: { upvotes: req.user._id },
      });
      req.flash("success", "removed your like");
      res.redirect(`/hotels/${id}`);
    } else if (disLikeExists) {
      await Hotel.findByIdAndUpdate(id, {
        $pull: { downvotes: req.user._id },
        $push: { upvotes: req.user._id },
      });
      req.flash("success", "changed dislike to like");
      res.redirect(`/hotels/${id}`);
    } else {
      const hotel = await Hotel.findById(id);
      hotel.upvotes.push(req.user);
      await hotel.save();
      req.flash("success", "added a like");
      res.redirect(`/hotels/${id}`);
    }
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};
module.exports.onDislike = async (req, res) => {
  try {
    const { id } = req.params;
    const likeExists = await Hotel.findOne({
      _id: id,
      upvotes: req.user._id,
    });
    const disLikeExits = await Hotel.findOne({
      _id: id,
      downvotes: req.user._id,
    });
    // check if user has already disliked -> remove that dislike
    // check if user has already liked -> change from like to dislike
    // else -> add a new dislike
    if (disLikeExits) {
      await Hotel.findByIdAndUpdate(id, {
        $pull: { downvotes: req.user._id },
      });
      req.flash("success", "removed your dislike");
      res.redirect(`/hotels/${id}`);
    } else if (likeExists) {
      await Hotel.findByIdAndUpdate(id, {
        $pull: { upvotes: req.user._id },
        $push: { downvotes: req.user._id },
      });
      req.flash("success", "changed from like to dislike");
      res.redirect(`/hotels/${id}`);
    } else {
      const hotel = await Hotel.findById(id);
      hotel.downvotes.push(req.user);
      await hotel.save();
      req.flash("success", "added a dislike");
      res.redirect(`/hotels/${id}`);
    }
  } catch (error) {
    console.log(error);
    req.flash("error", "Something went wrong");
    res.send(error);
  }
};

module.exports.contactPage=(req, res) => {
    res.render("contact", { page: "Contact" });
  };
  module.exports.sendMail= async (req, res) => {
    try {
      await sendEmail(req.body.contact);
      res.flash("success", "mail send successfully");
      res.redirect("/contact");
    } catch (error) {
      console.log(error);
      req.flash("error", "Something went wrong");
      res.send(error);
    }
  }
  module.exports.showLandingPage=(req, res) => {
    res.render("landing", { page: "Home - StaySense" });
  }