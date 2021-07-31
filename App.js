import React from "react";
import Card from "./Card";
import dataStructures from "./DataStructures";

function CreateCard(card) {
  return <Card name={card.name} img={card.imgURL} codeLink={card.codeLink} />;
}

function App() {
  return (
    <div>
      <h1 className="heading">Data Structures</h1>
      {dataStructures.map(CreateCard)}
    </div>
  );
}

export default App;
