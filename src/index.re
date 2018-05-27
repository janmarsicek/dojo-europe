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

module ZoomableGroup = {
  [@bs.module "react-simple-maps"]
  external zoomableGroup : ReasonReact.reactClass = "ZoomableGroup";

  [@bs.deriving abstract]
  type jsPropsT = {
    center: list(int),
    disablePanning: bool,
  };

  let make = (~center, ~disablePanning, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=zoomableGroup,
      ~props=jsPropsT(~center, ~disablePanning),
      children,
    );
};

ReactDOMRe.renderToElementWithId(
  <ComposableMap
    projectionConfig=(
      ComposableMap.projectionConfigT(~scale=205, ~rotation=[(-11), 0, 0])
    )
    width=980
    height=551>
    <ZoomableGroup center=[0, 20] disablePanning=true>
      (ReasonReact.string("dd"))
    </ZoomableGroup>
  </ComposableMap>,
  "main",
);