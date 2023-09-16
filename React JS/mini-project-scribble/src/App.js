import React, { useState, useEffect } from "react";

import Header from "./components/Header";
import Footer from "./components/Footer";
import Form from "./components/Form";
import List from "./components/List";

const App = () => {
  const [list, SetList] = useState(localStorage.list ? JSON.parse(localStorage.list) : []);

  useEffect(() => {
    localStorage.list = JSON.stringify(list);
  }, [list]);

  const addNoteToList = (note) => {
    SetList([...list, note]);
  };
  const deleteNoteFromList = (index) => {
    const newArr = list.filter((item, idx) => index !== idx);
    SetList(newArr);
  };

  return (
    <React.Fragment>
      <Header />
      <Form addNoteToList={addNoteToList} />
      <List list={list} deleteNoteFromList={deleteNoteFromList} />
      <Footer />
    </React.Fragment>
  );
};

export default App;
