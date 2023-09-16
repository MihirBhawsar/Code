import React, { useState } from "react";
const Note = (props) => {
  const [isExpanded, setExpanded] = useState(false);
  const expandParagraph = () => {
    setExpanded(!isExpanded);
  };
  return (
    <React.Fragment>
      <h1 onClick={expandParagraph}>{props.title}</h1>
      {isExpanded ? <p>{props.content}</p> : null}
    </React.Fragment>
  );
};

export default Note;
