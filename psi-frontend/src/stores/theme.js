import { defineStore } from 'pinia'

export const themeStore = defineStore('theme', {
  state: () => ({
    isDarkTheme: false
  }),
  getters: {
    getIsDark: (state) => state.isDarkTheme
  },
  actions: {
    changeDark() {
      // console.log('22222222', this.isDarkTheme)
      this.isDarkTheme = !this.isDarkTheme
      // console.log('222333333', this.isDarkTheme)
    }
  }
})
