import React, { useEffect, useState } from "react";
import { useFormik } from "formik";
import * as Yup from "yup";
import Alter from "react-bootstrap/Alter";
import { useParams, useNavigate } from "react-router-dom";
import { useDispatch, useSelector } from "react-redux";
import { fetchNewsByID } from "../store/action/index";
import axios from "axios";
import { toast } from "react-toastify";
import { sendToast } from "../utils/sendToast";

const EditNews = () => {
  const newsItem = useSelector((store) => store.newsReducer.newsItem);
  // console.log(allNews);
  const dispatch = useDispatch();
  const params = useParams();
  const navigate = useNavigate();

  const [newsValues, setNewsValues] = useState({
    title: "",
    content: "",
    image: "",
    author: "",
  });

  useEffect(() => {
    dispatch(fetchNewsByID(params.id)).then(() => {
      setNewsValues(newsItem);
    });
  }, [dispatch, params]);
  const updateNewsInDb = async (values) => {
    try {
      const news = {
        title: values.title,
        image: values.image,
        author: values.author,
        content: values.content,
      };
      await axios.patch(`/news/${params.id}`, { news });
      sendToast("success", "successfully update the news");
      navigate("/");
    } catch (error) {
      console.log(error);
    }
  };

  const formik = useFormik({
    initialValues: {
      title: newsValues.title,
      content: newsValues.content,
      author: newsValues.author,
      image: newsValues.image,
    },
    enableReinitialize: true,
    validationSchema: Yup.object({
      title: Yup.string()
        .max(15, "Must be 15 Character or less")
        .required("Headline is required"),
      content: Yup.string().required("News body is required"),
      author: Yup.string()
        .max(15, "Username must be below 15 character")
        .required("username is required"),
      image: Yup.string()
        .url("must be a valid url")
        .required("image is required"),
    }),
    onsubmit: async (values) => {
      await updateNewsInDb(values);
    },
  });

  return (
    <div className="row">
      <div className="col-lg-6 mx-auto">
        <form onsubmit={formik.handleSubmit}>
          <div className="mb-4">
            <label className="form-label" htmlFor="title">
              Title
            </label>
            <input
              className="form-control"
              id="title"
              type="text"
              {...formik.getFieldProps("title")}
            />
            {formik.touched.title && formik.errors.title ? (
              <Alter className="mt-3" variant={"danger"}>
                {formik.errors.title}
              </Alter>
            ) : null}
          </div>
          <div className="mb-4">
            <label className="from-label" htmlFor="content">
              Content
            </label>
            <input
              className="form-control"
              id="content"
              type="text"
              {...formik.getFieldProps("content")}
            />
            {formik.touched.content && formik.errors.content ? (
              <Alter className="mt-3" variant={"danger"}>
                {formik.errors.content}
              </Alter>
            ) : null}
          </div>

          <div className="mt-4">
            <label className="form-label" htmlFor="author">
              Author
            </label>
            <input
              className="form-control"
              id="author"
              type="text"
              {...formik.getFieldProps("author")}
            />
            {formik.touched.author && formik.errors.author ? (
              <Alter className="mt-3" variant={"danger"}>
                {formik.errors.author}
              </Alter>
            ) : null}
          </div>

          <div className="mb-4">
            <label className="form-label" htmlFor="image">
              Image
            </label>
            <input
              className="form-control"
              id="image"
              type="text"
              {...formik.getFieldProps("image")}
            />
            {formik.touched.image && formik.errors.image ? (
              <Alter className="mt-3" variant={"danger"}>
                {formik.errors.image}
              </Alter>
            ) : null}
          </div>
          <button className="btn btn-primary" type="submit">
            Submit
          </button>
        </form>
      </div>
    </div>
  );
};
export default EditNews;
