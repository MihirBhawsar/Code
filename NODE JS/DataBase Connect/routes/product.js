const express = require("express");
// instantiate a router
const router = express.Router();
const productModel = require("../models/product");

// REST
// index -> display all products
router.get("/products", async function (req, res) {
  try {
    const products = await productModel.find();
    res.render("index", { products });
  } catch (error) {
    res.send(error);
  }
});

// new -> shows a form
router.get("/product/new", function (req, res) {
  res.render("new");
});
// create -> insert a product into db
router.post("/product", async function (req, res) {
  try {
    let inStock = req.body.inStock ? true : false;
    const newProduct = new productModel({
      name: req.body.name,
      price: req.body.price,
      sellerName: req.body.sellerName,
      sellerAddress: req.body.sellerAddress,
      sellerPhone: req.body.sellerPhone,
      inStock: inStock,
    });

    await newProduct.save();
    console.log("product added to db");
    res.redirect("/products");
  } catch (error) {
    res.send(error);
  }
});

// show -> displays details of one product
router.get("/product/:id", async function (req, res) {
  try {
    const product = await productModel.findById(req.params.id);
    res.render("show", { product });
  } catch (error) {
    console.log(error);
  }
});

// edit -> form
router.get("product/:id/edit", function (req, res) {
  res.render("edit", { id: req.params.id });
});

// update -> update info in db
router.patch("/product/:id", async function (req, res) {
  try {
    let inStock = req.body.inStock ? true : false;
    const dataOfProductToUpdate = {
      name: req.body.name,
      price: req.body.price,
      sellerName: req.body.sellerName,
      sellerAddress: req.body.sellerAddress,
      sellerPhone: req.body.sellerPhone,
      inStock: inStock,
    };
    await productModel.findByIdAndUpdate(req.params.id, dataOfProductToUpdate);
    res.redirect("/products");
  } catch (error) {
    console.log(error);
  }
});

//destroy
router.delete("/products/:id", async function (req, res) {
  try {
    await productModel.findByIdAndDelete(req.params.id);
    res.redirect("/products");
  } catch (error) {
    console.log(error);
  }
});

module.exports = router;
