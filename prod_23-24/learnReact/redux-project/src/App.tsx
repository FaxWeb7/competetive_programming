import { FC } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { counterActions, selectCount } from './store/counter/counter.slice'

export const App: FC = () => {
  const counterState = useSelector(selectCount)
  const dispatch = useDispatch()

  return (
    <div style={{width: '100vw', display: 'flex', flexDirection: 'column', alignItems: 'center', gap: 15}}>
      <h1>{counterState.value}</h1>
      <button onClick={() => dispatch(counterActions.increment())}>Increment</button>
      <button onClick={() => dispatch(counterActions.decrement())}>Decrement</button>
      <button onClick={() => dispatch(counterActions.amountIncrement(10))}>Increment by 10</button>
    </div>
  )
}