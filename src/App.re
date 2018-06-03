let component = ReasonReact.statelessComponent("App");

let defaultStyle =
  Geography.cssT(
    ~fill="#ECEFF1",
    ~stroke="#607D8B",
    ~strokeWidth=0.75,
    ~outline="none",
  );

let hoverStyle =
  Geography.cssT(
    ~fill="#607D8B",
    ~stroke="#607D8B",
    ~strokeWidth=0.75,
    ~outline="none",
  );

let pressedStyle =
  Geography.cssT(
    ~fill="#FF5722",
    ~stroke="#607D8B",
    ~strokeWidth=0.75,
    ~outline="none",
  );

let make = (~name, _children) => {
  ...component,
  render: _self =>
    <div>
      <h1> (ReasonReact.string("Hello " ++ name ++ "!")) </h1>
      <Wrapper
        render=(
          markers =>
            <div>
              <ComposableMap
                width=980
                height=551
                projectionConfig=(
                  ComposableMap.projectionConfigT(
                    ~scale=205,
                    ~rotation=[(-11), 0, 0],
                  )
                )>
                <ZoomableGroup center=[0, 20] disablePanning=true>
                  <Geographies geography="/world-50m.json">
                    (
                      (geographies, projection) =>
                        geographies
                        |> Array.to_list
                        |> List.filter(geography =>
                             Geography.id(geography) !== "ATA"
                           )
                        |> Array.of_list
                        |> Array.mapi((i, geography) =>
                             <Geography
                               key=(string_of_int(i))
                               geography
                               projection
                               style=(
                                 Geography.styleT(
                                   ~default=defaultStyle,
                                   ~hover=hoverStyle,
                                   ~pressed=pressedStyle,
                                 )
                               )
                             />
                           )
                    )
                  </Geographies>
                  <Markers>
                    (
                      markers
                      |> Array.mapi((i, marker) =>
                           <Marker
                             key=(string_of_int(i))
                             marker
                             style=(
                               Marker.styleT(
                                 ~default=Marker.cssT(~fill="#FF5722"),
                                 ~hover=Marker.cssT(~fill="#FFFFFF"),
                                 ~pressed=Marker.cssT(~fill="#FF5722"),
                               )
                             )>
                             <circle
                               cx="0"
                               cy="0"
                               r="10"
                               style=(
                                 ReactDOMRe.Style.make(
                                   ~stroke="#FF5722",
                                   ~strokeWidth="3",
                                   ~opacity="0.9",
                                   (),
                                 )
                               )
                             />
                             <text
                               textAnchor="middle"
                               y=(string_of_int(Marker.markerOffset(marker)))
                               style=(
                                 ReactDOMRe.Style.make(
                                   ~fontFamily="Roboto, sans-serif",
                                   ~fill="#607D8B",
                                   (),
                                 )
                               )>
                               (ReasonReact.string(Marker.name(marker)))
                             </text>
                           </Marker>
                         )
                    )
                  </Markers>
                </ZoomableGroup>
              </ComposableMap>
            </div>
        )
      />
    </div>,
};
