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
        render=(markers =>
          <div>
            (markers
            |> Array.mapi((i, marker) =>
              <div
                key=(string_of_int(i))
              >
                (ReasonReact.string(Fetcher.username(marker)))
              </div>)
            |> ReasonReact.array)
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
              </ZoomableGroup>
            </ComposableMap>
          </div>
        )

        /* customRender=(markers =>
            markers
            |> Array.mapi((i, marker) =>
              <div
                key=(string_of_int(i))
              >
                (ReasonReact.string(Fetcher.username(marker)))
              </div>)
            |> ReasonReact.array) */
      />


  /* <ComposableMap
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
        </ZoomableGroup>
      </ComposableMap> */
    </div>,
};
