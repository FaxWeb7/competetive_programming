import { FC } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { actions, selectCount } from './store/counter/counter.slice'

export const App: FC = () => {
  const counterState = useSelector(selectCount)
  const dispatch = useDispatch()

  return (
    <div style={{width: '100vw', display: 'flex', flexDirection: 'column', alignItems: 'center', gap: 15}}>
      <h1>{counterState.value}</h1>
      <button onClick={() => dispatch(actions.increment())}>Increment</button>
      <button onClick={() => dispatch(actions.decrement())}>Decrement</button>
      <button onClick={() => dispatch(actions.amountIncrement(10))}>Increment by 10</button>
    </div>
  )
}