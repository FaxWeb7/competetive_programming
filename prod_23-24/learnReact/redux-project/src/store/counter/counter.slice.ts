import { PayloadAction, createSlice } from '@reduxjs/toolkit'
import { ICounterState } from '../../types/counter.types'
import { RootState } from '../store'

const initialState: ICounterState = {
  value: 0
}

export const counterSlice = createSlice({
  name: 'counter',
  initialState,
  reducers: {
    increment: state => {
      state.value += 1
    },
    decrement: state => {
      state.value -= 1
    },
    amountIncrement: (state, action: PayloadAction<number>) => {
      state.value += action.payload
    }
  }
})

export const { actions: counterActions, reducer: counterReducer } = counterSlice
export const selectCount = (state: RootState) => state.counter