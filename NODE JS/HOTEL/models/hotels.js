const mongoose = require("mongoose");

const hotelSchema = new mongoose.Schema({
  name: {
    type: String,
    require: true,
    trim: true,
  },
  price: {
    type: Number,
    require: true,
    min: 500,
    max: 100000,
  },
  address: String,
  description: String,
  image: [String],
  createAt: {
    type: Date,
    default: Date.now(),
  },
  reviews: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "review",
    },
  ],
  sumOfRating: {
    type: Number,
    default: 0,
  },
  averageRating: {
    type: Number,
    default: 0,
  },
  totalRating: {
    type: Number,
    default: 0,
  },
  location: {
    type: {
			type: String
		},
    coordinates: [Number]
  },
  author: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "user",
  },
  upvotes: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "user",
    },
  ],
  downvotes: [
    {
      type: mongoose.Schema.Types.ObjectId,
      ref: "user",
    },
  ],
});

module.exports = mongoose.model("hotel", hotelSchema);
