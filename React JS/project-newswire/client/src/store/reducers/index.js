import { createStore, compose, applyMiddleware } from "redux";
import promiseMiddleware from "redux-promise";
import combinedReducers from "./reducers/index";

const ReduxStore = () => {
  const webToolEnhancers =
    window._REDUX_DEVTOOLS_EXTENSION_COMPOSE__ || compose;
  const middlewareEnhancers = applyMiddleware(promiseMiddleware);
  const composeEnhancers = webToolEnhancers(middlewareEnhancers);
  const store = createStore(combinedReducers, composeEnhancers);
  return store;
};
export default ReduxStore;
