import React, { useEffect } from "react";
import { LinkContainer } from "react-router-bootstrap";
import { useDispatch, useSelector } from "react-redux";
import { feactNewsById } from "../stroe/actions/index";
import { useParams, useNavigate } from "react-router-dom";
import axios from "axios";
import Moment from "react-moment";
import { sendToast } from "../utils/sendToast";

const ShowNews = () => {
  const newsItem = useSelector((store) => store.newsReducer.newsItem);
  const dispatch = useDispatch();
  const params = useParams();
  const navigate = useNavigate();

  useEffect(() => {
    dispatch(feactNewsById(params.id));
  }, [dispatch, params]);

  const deleteNewsFromDb = async () => {
    await axios.delete(`/news/${params.id}`);
    sendToast("success", "successfully deleted the news");
    navigate("/");
  };

  return (
    <React.Fragment>
      {newsItem ? (
        <div className="article_container">
          <h1>{newsItem.title}</h1>
          <div
            style={{ backgroundImage: `url(${newsItem.image})` }}
            className="image"
          />
          <div className="author">
            <span>created by: {newsItem.author}</span>
            <div>
              created at:{" "}
              <Moment format="DD/MM/YYYY">{newsItem.createAt}</Moment>
            </div>
          </div>
          <div className="my-3 content ">{newsItem.content}</div>
          <LinkContainer to={`/news/${params.id}/edit`}>
            <button className="btn btn-warning mb-3"> Edit</button>
          </LinkContainer>
          <button
            onClick={deleteNewsFromDb}
            className="ms-2 btn btn-danger mb-3"
          >
            Delete
          </button>
        </div>
      ) : null}
    </React.Fragment>
  );
};

export default ShowNews;
