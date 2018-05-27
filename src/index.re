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

module Geographies = {
  [@bs.module "react-simple-maps"]
  external geographies : ReasonReact.reactClass = "Geographies";

  [@bs.deriving abstract]
  type jsPropsT = {geography: string};

  let make = (~geography, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographies,
      ~props=jsPropsT(~geography),
      children,
    );
};

module Geography = {
  [@bs.module "react-simple-maps"]
  external geographyM : ReasonReact.reactClass = "Geography";

  [@bs.deriving abstract]
  type cssT = {
    fill: string,
    stroke: string,
    strokeWidth: float,
    outline: string,
  };
  [@bs.deriving abstract]
  type styleT = {
    default: cssT,
    hover: cssT,
    pressed: cssT,
  };
  [@bs.deriving abstract]
  type geographyT = {id: string};
  [@bs.deriving abstract]
  type jsPropsT = {
    geography: geographyT,
    projection: string,
    style: styleT,
  };

  let make = (~geography, ~projection, ~style, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographyM,
      ~props=jsPropsT(~geography, ~projection, ~style),
      children,
    );
};

ReactDOMRe.renderToElementWithId(
  <Wrapper>
    <ComposableMap
      projectionConfig=(
        ComposableMap.projectionConfigT(~scale=205, ~rotation=[(-11), 0, 0])
      )
      width=980
      height=551>
      <ZoomableGroup center=[0, 20] disablePanning=true>
        <Geographies geography="/world-50m.json">
          (
            (geographies, projection) =>
              geographies
              |> Array.to_list
              |> List.filter(geography => Geography.id(geography) != "ATA")
              |> Array.of_list
              |> Array.mapi((i, geography) =>
                   <Geography
                     key=(string_of_int(i))
                     geography
                     projection
                     style=(
                       Geography.styleT(
                         ~default=
                           Geography.cssT(
                             ~fill="#ECEFF1",
                             ~stroke="#607D8B",
                             ~strokeWidth=0.75,
                             ~outline="none",
                           ),
                         ~hover=
                           Geography.cssT(
                             ~fill="#607D8B",
                             ~stroke="#607D8B",
                             ~strokeWidth=0.75,
                             ~outline="none",
                           ),
                         ~pressed=
                           Geography.cssT(
                             ~fill="#FF5722",
                             ~stroke="#607D8B",
                             ~strokeWidth=0.75,
                             ~outline="none",
                           ),
                       )
                     )
                   />
                 )
          )
        </Geographies>
      </ZoomableGroup>
    </ComposableMap>
  </Wrapper>,
  "main",
);