/* file: Greeting.re */
module Greeting = {
  let component = ReasonReact.statelessComponent("Greeting");

  /* underscores before names indicate unused variables. We name them for clarity */
  let make = (~name, _children) => {
    ...component,
    render: _self =>
      <button> (ReasonReact.string("Hello " ++ name ++ "!")) </button>,
  };
};

/* file: Index.re */

ReactDOMRe.renderToElementWithId(<Greeting name="John" />, "main");

module ComposableMap = {
  [@bs.module "react-simple-maps"]
  external composableMap : ReasonReact.reactClass = "ComposableMap";

  type projectionConfigT = {
    scale: int,
    rotation: list(int),
  };
  [@bs.deriving abstract]
  type jsPropsT = {
    width: int,
    height: int,
    projectionConfig: projectionConfigT,
  };

  let make = (~width, ~height, ~projectionConfig, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=composableMap,
      ~props=jsPropsT(~width, ~height, ~projectionConfig),
      children,
    );
};