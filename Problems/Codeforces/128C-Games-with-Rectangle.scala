import scala.io.StdIn.readLine

object Main extends App {
  val mod: Long = 1000000007
  val s: Array[String] = readLine().split(' ')
  val n: Long = s(0).toLong
  val m: Long = s(1).toLong
  val k: Long = s(2).toLong
  if(2 * k >= n || 2 * k >= m) println(0)
  else println(C(n - 1, 2 * k) * C(m - 1, 2 * k) % mod)

  def fact(n: Long): Long =
    if(n == 0) 1
    else n * fact(n - 1) % mod

  def pow(b: Long, p: Long): Long =
    if(p == 0) 1
    else {
      val t: Long = pow(b, p / 2)
      if(p % 2 == 1) t * t % mod * b % mod
      else t * t % mod
    }

  def mul_inv(x: Long): Long = pow(x, mod - 2)

  def C(n: Long, k: Long): Long =
    fact(n) * mul_inv(fact(k) * fact(n - k) % mod) % mod
}