type fetchedData = array(Fetcher.data);

type state = {
  loading: bool,
  markers: fetchedData,
};

type action =
  | Loaded(fetchedData)
  | Loading(bool);

let component = ReasonReact.reducerComponent("Wrapper");

let make = (~render, _children) => {
  ...component,
  initialState: () => {
    markers: [||],
    loading: false,
  },
  reducer: (action, state) =>
  switch (action) {
  | Loading(bool) => ReasonReact.Update({...state, loading: bool})
  | Loaded(markers) => ReasonReact.Update({markers: markers, loading: false})
  },
  didMount: self => {
    self.send(Loading(true));
    Fetcher.fetchGet(
      ~url="https://immense-river-25513.herokuapp.com/locations",
      ~cb=data => self.send(Loaded(data))
    )
  },
  render: ({state: { loading, markers }}) => {
    let foo = switch(loading, markers) {
    | (true, _) => "Loading..."
    | (false, [||]) => "Loaded, no results"
    | (false, _) => "Loaded"
    };

    <div>
      <h2>(ReasonReact.string(foo))</h2>
      (render(markers))
      /* (children(markers)) */
    </div>
  },
}
