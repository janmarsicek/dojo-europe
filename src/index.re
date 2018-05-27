module ComposableMap = {
  [@bs.module "react-simple-maps"]
  external composableMap : ReasonReact.reactClass = "ComposableMap";

  [@bs.deriving abstract]
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
ReactDOMRe.renderToElementWithId(
  <ComposableMap
    projectionConfig=(
      ComposableMap.projectionConfigT(~scale=205, ~rotation=[(-11), 0, 0])
    )
    width=980
    height=551
  />,
  "main",
);